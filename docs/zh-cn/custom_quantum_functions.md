# ��ζ�������̵Ĺ���

���ںܶ�����˵���ƻ����̿ɲ�ֻ������ĵ��Է����㰴���Ǹ�����ô�򵥡���϶���ʵ�ֱȼ򵥰����ͺ�����ӵĹ��ܡ�QMK��������ע�����Ĺ���, ���ǹ���, ���⣬�������Զ�������ڲ�ͬ����µ���Ϊ��

��ҳ���ٶ��κ������QMK֪ʶ�����Ķ�[���QMK](understanding_qmk.md)�����ڸ������Ĳ��������ⷢ����ʲô��

## A Word on Core vs ���� vs ����

���ǰ�qmk��֯��һ����νṹ��

* Core (`_quantum`)
  * Keyboard/Revision (`_kb`)
    * Keymap (`_user`)

����������ÿһ�������������ڶ����ϼ�һ��`_kb()`�� `_user()` ��׺�� �����ڼ���/�޶���ʹ��`_kb()`��׺���ڲ��ֲ�ʹ��`_user()`��׺��

�ڼ���/�޶��㶨�庯��ʱ��`_kb()`��ִ���κδ���ǰ�ȵ���`_user()`�Ǳ�Ҫ�ģ���Ȼ���ֲ㺯���Ͳ�Ҫ�����á�
<!-- �������⣺�����Ǿ䷭��Ĳ�̫��-->
# �Զ������

��ĿǰΪֹ������������Ǹ������м������Ϊ�򴴽��µļ��롣�Ӵ���Ƕ�������Щ�����������ơ�

## ����һ���¼���

���������һ������ö�ٳ���ȫ����Ҳ���Ǹ�����������ֲ�����Ψһ��ֵ��QMKû��ֱ������������ֵ��С�������ṩ��һ��`SAFE_RANGE`�ꡣ�������ö��ʱ��`SAFE_RANGE`����֤��ȡ����Ψһ�ļ���ֵ��


����ö��������������ӡ������ӵ�`keymap.c`�Ļ�����ڲ���������`FOO`��`BAR`�ˡ�

```c
enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR
};
```

## Ϊ�������Ϊ���

���㸲��һ���Ѵ��ڰ�������Ϊʱ���������Ϊ�����¼�ʱ����Ҫ��`process_record_kb()`��`process_record_user()`���������������ڼ���������ʵ���¼�������ǰ��QMK���á����������������`true`��QMK�����������ķ�ʽ������롣�������Ժܷ������չ����Ĺ��ܶ������滻���������������`false` QMK����������������Ȼ���ͼ���̧���ǰ����¼�����������ˡ�

��ĳ�������»��ͷ�ʱ���������ᱻ���á�

### process_record_user()`����ʾ��ʵ��

����������������¡��Զ�����һ������`FOO`�ļ������Ϊ�����������ڰ��»س�ʱ����������

```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FOO:
      if (record->event.pressed) {
        // ����ʱ��Щʲô
      } else {
        // �ͷ�ʱ��Щʲô
      }
      return false; // �����˼������н�һ������
    case KC_ENTER:
      // �����»س�ʱ��������
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_qwerty);
      }
      return true; // ��QMK�����س�����/�ͷ��¼�
    default:
      return true; // ����������������
  }
}
```

### `process_record_*` �����ĵ�

* ����/�޶�: `bool process_record_kb(uint16_t keycode, keyrecord_t *record)`
* ����: `bool process_record_user(uint16_t keycode, keyrecord_t *record)`

`keycode(����)`�������ڲ����϶���ģ�����`MO(1)`, `KC_L`, �ȵȡ� ��Ҫ�� `switch...case` ����������Щ�¼���

`record`��������ʵ�ʰ�������Ϣ��

```c
keyrecord_t record {
  keyevent_t event {
    keypos_t key {
      uint8_t col
      uint8_t row
    }
    bool     pressed
    uint16_t time
  }
}
```

# LED����

qmk�ṩ�˶�ȡHID�淶������5��LED�ķ�����:

* `USB_LED_NUM_LOCK`
* `USB_LED_CAPS_LOCK`
* `USB_LED_SCROLL_LOCK`
* `USB_LED_COMPOSE`
* `USB_LED_KANA`

�����������Ӧ������LED״̬��λ��λ��
�����ַ������Ի������LED״̬��

* ͨ��ִ�� `led_set_user()`
* ͨ������ `host_keyboard_leds()`

## `led_set_user()`

��5��LED���κ�һ����״̬��Ҫ�ı�ʱ���˺����������á��˺���ͨ����������LED������
ʹ��`IS_LED_ON(usb_led, led_name)`��`IS_LED_OFF(usb_led, led_name)`�������������LED״̬��

!> `host_keyboard_leds()`���ܻ���`led_set_user()`������ǰ������ֵ��

### `led_set_user()`����ʾ��ʵ��

```c
void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinLow(B0);
    } else {
        writePinHigh(B0);
    }
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinLow(B1);
    } else {
        writePinHigh(B1);
    }
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinLow(B2);
    } else {
        writePinHigh(B2);
    }
    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {
        writePinLow(B3);
    } else {
        writePinHigh(B3);
    }
    if (IS_LED_ON(usb_led, USB_LED_KANA)) {
        writePinLow(B4);
    } else {
        writePinHigh(B4);
    }
}
```

### `led_set_*`�����ĵ�

* ����/�޶�: `void led_set_kb(uint8_t usb_led)`
* ����: `void led_set_user(uint8_t usb_led)`

## `host_keyboard_leds()`

������������᷵������յ���LED״̬�����������`led_set_*`֮���ȡLED״̬ʱ�����ã�������[`matrix_scan_user()`](#����ɨ�����).
Ϊ�˱�ݣ��������`IS_HOST_LED_ON(led_name)`��`IS_HOST_LED_OFF(led_name)` �꣬����ֱ�ӵ��úͼ��`host_keyboard_leds()`��

## ��������LED״̬

һЩ����ʵ����Ϊ��������LED��״̬�ṩ�˷���ķ�����

### Ergodox Boards

Ergodoxʵ�����ṩ`ergodox_right_led_1`/`2`/`3_on`/`off()`����ÿ��LED�����, Ҳ������ `ergodox_right_led_on`/`off(uint8_t led)` �������򿪻�ر����ǡ�

���⣬������ʹ��`ergodox_led_all_set(uint8_t n)`ָ������LED�����ȼ������ÿ��LED��`ergodox_right_led_1`/`2`/`3_set(uint8_t n)`��ʹ�������Ļ���`ergodox_right_led_set(uint8_t led, uint8_t n)`��

Ergodox boards ͬʱ������������ȼ���`LED_BRIGHTNESS_LO`��������ȼ���`LED_BRIGHTNESS_HI`(Ĭ�����).

# ���̳�ʼ������

���̳�ʼ�������м������衣�������Ǹ�����ȡ��������Ҫ��ʲô��

��������Ҫ��ʼ��������������˳���г���

* `keyboard_pre_init_*` - ���ڴ����������������ǰ���С���������Щ��Ҫ��ǰ���е�Ӳ����ʼ����
* `matrix_init_*` - �ڹ̼����������м䱻���á���ʱӲ���ѳ�ʼ����������δ��ʼ����
* `keyboard_post_init_*` - �ڹ̼�����������󱻵��á����������£���ġ����ƻ������붼���Է������

!> ���ڴ��������˵`keyboard_post_init_user`������Ҫ���õĺ���������, ��ʱ���������RGB�Ʒ��⡣

## ����Ԥ��ʼ������

����뼫�����У���������USB��ʼ��ǰ���С�

����֮�󲻾þ���ͱ���ʼ���ˡ�

���ڴ�����û���˵,���ò�������Ϊ����Ҫ����������Ӳ���ĳ�ʼ����

���������Ӳ����ʼ���Ļ����������ٺò�����(�����ʼ��LED����һ���).

### `keyboard_pre_init_user()`����ʾ��ʵ��

�������ڼ��̼����趨 B0, B1, B2, B3, �� B4 ��LED���š�

```c
void keyboard_pre_init_user(void) {
  // ���ü���Ԥ��ʼ������

  // ����LED����Ϊ���ģʽ
  setPinOutput(B0);
  setPinOutput(B1);
  setPinOutput(B2);
  setPinOutput(B3);
  setPinOutput(B4);
}
```

### `keyboard_pre_init_*` �����ĵ�

* ����/�޶�: `void keyboard_pre_init_kb(void)`
* ����: `void keyboard_pre_init_user(void)`

## �����ʼ������

�⽫���ھ����ʼ��ʱ�����ã���ĳЩӲ�����úú󣬵���һЩ���ܱ���ʼ��ǰ�� 

���������������ط����õ��Ķ�����ʱ�������ã�����Ӳ���޹أ�Ҳ����������������λ�á�


### `matrix_init_*`�����ĵ�

* ����/�޶�: `void matrix_init_kb(void)`
* ����: `void matrix_init_user(void)`


## ���̺��ʼ������

���Ǽ��̳�ʼ�������е����һ����������������ĳЩ���ԣ��������ã���Ϊ��ʱӦ�ö����ǽ��г�ʼ����


### `keyboard_post_init_user()`ʾ��ʵ��

��ʾ�������г�ʼ����ɺ����У�����RGB�ơ�

```c
void keyboard_post_init_user(void) {
  // ���ú��ʼ������
  rgblight_enable_noeeprom(); // ʹ��Rgb������������
  rgblight_sethsv_noeeprom(180, 255, 255); // ����ɫ���õ�����ɫ(��ɫ)������
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // ���ÿ��ٺ���ģʽ������
}
```

### `keyboard_post_init_*` �����ĵ�

* ����/�޶�: `void keyboard_post_init_kb(void)`
* ����: `void keyboard_post_init_user(void)`

# ����ɨ�����

���ܵĻ���Ҫ��`process_record_*()`�Զ�����̣������ַ�ʽ���ӵ��¼��У���ȷ�����벻��Լ��̲������������Ӱ�졣Ȼ�����ڼ���������£��б�Ҫ���о���ɨ�衣����Щ������Ҫ�ر�ע���������ܣ���Ϊ��ÿ�����ٱ�����10�Ρ�

### `matrix_scan_*`ʾ��ʵ��

������ӱ�����ʡ���ˡ���hook����һ�������ܼ������е�����֮ǰ����Ӧ���㹻�˽�qmk���ڲ��ṹ���Ա���û��ʾ��������±�д���������Ҫ��������[����һ��issue](https://github.com/qmk/qmk_firmware/issues/new)��[��Discord�������ǽ���](https://discord.gg/Uq7gcHh).

### `matrix_scan_*` �����ĵ�

* ����/�޶�: `void matrix_scan_kb(void)`
* ����: `void matrix_scan_user(void)`

�ú�����ÿ�ξ���ɨ��ʱ�����ã��������MCU��������������ͬ��������д����Ҫ��������Ϊ�������кܶ�Ρ�

������Զ������ɨ�����ʱ�õ������������Ҳ���������Զ���״̬���(����LED�ƻ�����Ļ)�������������û���������Ҳ�붨�����еĹ��ܡ�


# ���� ����/���� ����

�������֧�־Ϳ���ͨ��ֹͣһ��Ʊ�������ﵽ"����"��RGB�ƺͱ�����Ǻܺõ����ӡ�����Խ�Լ�ܺģ�Ҳ����������̷�ζ���ѡ�

��������������: `suspend_power_down_*`��`suspend_wakeup_init_*`, �ֱ���ϵͳ����кͻ���ʱ���á�


### suspend_power_down_user()��suspend_wakeup_init_user()ʾ��ʵ��


```c
void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
```

### ���� ����/���� �����ĵ�

* ����/�޶�: `void suspend_power_down_kb(void)` ��`void suspend_wakeup_init_user(void)`
* ����: `void suspend_power_down_kb(void)` �� `void suspend_wakeup_init_user(void)`

# ��ı����

ÿ����ı���������д��롣����ڲ�ָʾ���Զ���㴦������á�

### `layer_state_set_*` ʾ��ʵ��

����ʹ����Planck����ʾ����������� [RGB�����](feature_rgblight.md)ʹ֮����Ӧ

```c
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _RAISE:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _LOWER:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _PLOVER:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _ADJUST:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}
```
### `layer_state_set_*` �����ĵ�

* ����/�޶�: `uint32_t layer_state_set_kb(uint32_t state)`
* ����: `uint32_t layer_state_set_user(uint32_t state)`


��`״̬`�ǻ���bitmask, ���[���ָ���](keymap.md#���ֵĲ�״̬)


# ���籣������ (EEPROM)

�����������ó��ڵı����ڼ����С���Щ���ñ����������ص�EEPROM����粻����ʧ�� ���ÿ�����`eeconfig_read_kb`��`eeconfig_read_user`��ȡ��������`eeconfig_update_kb`��`eeconfig_update_user`д�롣�������ϣ���ܹ��л��Ĺ��ܺ�����(�����л�RGB��ָʾ�����⣬�������`eeconfig_init_kb`��`eeconfig_init_user`������EEPROMĬ��ֵ�� 

��ӵĲ��ֿ����ǣ��кܶ෽������ͨ��EEPROM�洢�ͷ������ݣ����Ҳ�û�������ַ����ǡ�������ȷ���ġ���ÿ������ֻ��һ��˫��(���ֽ�)�ռ䡣

��סEEPROM����д�������ġ�����д�������ܸߣ����ǲ�����ֻ������д��EEPROM�С������д��Ƶ�������MCU���������̡�

* ����������������ӣ���ô������ϣ������ʹ��������ԣ���Ϊ���൱���ӡ�

### ʾ��ʵ��

�������������������ã����Ҷ�д������ʹ�����û����֡�����һ�����ӵĺ������кܶ�����Ҫ����ʵ���ϣ���ʹ���˺ܶ�����������������


�����keymap.c�ļ��У������´������������:
```c
typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

user_config_t user_config;
```

���ϴ��뽨����һ���ṹ�壬�ýṹ����Դ洢���ò�������д��EEPROM�������㽫���趨���������Ϊ�ڽṹ������Ȼ���塣Ҫ��ס`bool` (����)ֵʹ��1λ, `uint8_t`ʹ��8λ, `uint16_t`ʹ��16λ������Ի�ϴ���ʹ�ã�����˳��Ǵ���ܻ������鷳����Ϊ�ǻ�ı�д��д����ֵ�� 

 `layer_state_set_*`������ʹ����`rgb_layer_change`��ʹ����`keyboard_post_init_user`��`process_record_user`������һ�С�

����Ҫʹ��`keyboard_post_init_user����Ҫ����`eeconfig_read_user()`�������ոմ����Ľṹ�塣Ȼ������������ʹ������ṹ���������Ĳ����еĹ��ܡ����������� 
```c
void keyboard_post_init_user(void) {
  // ���ò��ּ���ľ����ʼ��

  // ��EEPROM���û�����
  user_config.raw = eeconfig_read_user();

  // ��ʹ�ܣ�����Ĭ�ϲ�
  if (user_config.rgb_layer_change) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom_cyan(); 
    rgblight_mode_noeeprom(1);
  }
}
```
���Ϻ������ڶ�EEPROM���ú�����ʹ�ø�����������Ĭ�ϲ�RGB��ɫ��"raw"��ֵ�Ǵ����������"union"�����Ľṹ����ת�����ġ� 

```c
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _RAISE:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_magenta(); rgblight_mode_noeeprom(1); }
        break;
    case _LOWER:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_red(); rgblight_mode_noeeprom(1); }
        break;
    case _PLOVER:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_green(); rgblight_mode_noeeprom(1); }
        break;
    case _ADJUST:
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_white(); rgblight_mode_noeeprom(1); }
        break;
    default: //  ����������Ĭ�ϲ�
        if (user_config.rgb_layer_change) { rgblight_sethsv_noeeprom_cyan(); rgblight_mode_noeeprom(1); }
        break;
    }
  return state;
}
```
��������ֵʹ��ʱ��ı�RGB����ơ������������ֵ, Ϊ`process_record_user`����һ���¼������`RGB_LYR`������Ҫȷ�������ʹ��������RGB���룬ʹ�������ʾ������رգ��뽫������Ϊ��
```c

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FOO:
      if (record->event.pressed) {
        // ����ʱ����ʲô
      } else {
        // �ͷ�ʱ����ʲô
      }
      return false; // �����˼��Ľ�һ������
    case KC_ENTER:
        // �ڰ��»س�ʱ��������
        if (record->event.pressed) {
            PLAY_NOTE_ARRAY(tone_qwerty);
        }
        return true; // ��QMK�����س�����/�ͷ��¼�
    case RGB_LYR:  // ������underglow��Ϊ��ָʾ��������ʹ�á�
        if (record->event.pressed) { 
            user_config.rgb_layer_change ^= 1; // �л�״̬
            eeconfig_update_user(user_config.raw); // ��EEPROMд����״̬
            if (user_config.rgb_layer_change) { // �����״̬��ʹ��
                layer_state_set(layer_state);   // ��ô���̸��²���ɫ
            }
        }
        return false; break;
    case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT: // �������е�RGB���� (see quantum_keycodes.h, L400 ���Բο�)
        if (record->event.pressed) { //����ʧ�ܲ�ָʾ��������ı����������Ҫ��������
            if (user_config.rgb_layer_change) {        // ����ʹ��ʱ
                user_config.rgb_layer_change = false;  // ʧ�ܣ�Ȼ�� 
                eeconfig_update_user(user_config.raw); // ��EEPROMд������
            }
        }
        return true; break;
    default:
      return true; // ������������
  }
}
```
�����Ҫ����`eeconfig_init_user`���������Ե�EEPROM����ʱ������ָ��Ĭ��ֵ, �����Զ����������ǿ������EEPROM������`EEP_RST`�����[Bootmagic](feature_bootmagic.md)���������磬���Ҫ��Ĭ�����������RGB��ָʾ��������Ĭ��ֵ

```c
void eeconfig_init_user(void) {  // EEPROM��������
  user_config.raw = 0;
  user_config.rgb_layer_change = true; // ������ҪĬ��ʹ��
  eeconfig_update_user(user_config.raw); // ��EEPROMд��Ĭ��ֵ

  // use the non noeeprom versions, ��Ҫ��EEPROMд����Щֵ
  rgblight_enable(); // Ĭ��ʹ��RGB
  rgblight_sethsv_cyan();  // Ĭ��������ɫ
  rgblight_mode(1); // Ĭ�����ó���
}
```

Ȼ��������ˡ�RGB��ָʾ����������������ʱ������������û�һֱ���棬��������¼��̡������ʹ������RGB���룬��ָʾ��ʧ�ܣ��������������������ˡ� 

### 'EECONFIG' �����ĵ�

* ����/�޶�: `void eeconfig_init_kb(void)`, `uint32_t eeconfig_read_kb(void)`��`void eeconfig_update_kb(uint32_t val)`
* ����: `void eeconfig_init_user(void)`, `uint32_t eeconfig_read_user(void)`��`void eeconfig_update_user(uint32_t val)`

`val` ������д��EEPROM��ֵ��`eeconfig_read_*`�������EEPROM����һ��32λ(˫��)��ֵ��

# �Զ������-�����ٽ�ֵ(TAPPING_TERM)
Ĭ�������,����-�����ٽ�ֵ��ȫ��ͳһ�ģ����Ҳ���ͨ�����������á����ڴ�����û���˵��ܺá���������Щ����£�����`LT`����˵������ʱ��˫���ܼ����������󣬿�������Ϊ��Щ���������ļ������װ�ס��Ϊ�˲���ÿ�����Զ�����룬�����ܿ���Ϊÿ��������`TAPPING_TERM`��

��ʹ��������ܵĻ�, Ҫ����`config.h`����`#define TAPPING_TERM_PER_KEY`��


## `get_tapping_term`ʾ��ʵ��

��Ҫ�޸Ļ��ڼ����`TAPPING TERM`,��Ҫ��`keymap.c`�ļ�������´���: 

```c
uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case SFT_T(KC_SPC):
      return TAPPING_TERM + 1250;
    case LT(1, KC_GRV):
      return 130;
    default:
      return TAPPING_TERM;
  }
}
```

### `get_tapping_term` �����ĵ�

������ƪ����������,�������Ҫquantum���߼��̼���ĺ�����ֻҪ�û����������ɡ�
