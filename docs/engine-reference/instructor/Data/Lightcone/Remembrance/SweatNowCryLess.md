# `src/Defination/Data/Lightcone/Remembrance/SweatNowCryLess.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"SweatNowCryLess"` · base stats `SetAllyBaseStats(1058, 529, 198)`

| ท่อน | โค้ด |
|---|---|
| CR `10 + 2S` | `Reset_List` |
| memosprite ยังอยู่ → DMG `20 + 4S` (ครั้งเดียวตลอดการต่อสู้) | `Before_turn_List` + `isHaveToAddBuff(ptr, "SweatNowCryLess")` |

## จุดที่ควรระวัง

- **`ptr->memospriteList[0]` เข้าถึงโดยไม่เช็คว่ามีสมาชิกไหม** → **ถ้าผู้สวมไม่ใช่ path Remembrance จะ crash** · ใบอื่นในโฟลเดอร์วน `memospriteList` ซึ่งปลอดภัยกว่า
- **`isHaveToAddBuff` แบบ 2 args ไม่มีอายุ** → บัฟลงครั้งเดียวแล้วอยู่ถาวร แม้ memosprite ตายไปแล้วก็ไม่ถอน · ถ้า kit ระบุว่าเป็นเงื่อนไขต่อเนื่อง ควรมีโค้ดถอน (แบบที่ `Reminiscence.h` ทำ)
