// Room: /d/henshan/shanlu14.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣ɽ·ת��ܽ�ط壬����ԶԶ�����ؾ��󣬶��Ϸ���
ͨ�������š�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"       : __DIR__"cangjingdian",
           "southeast"  : __DIR__"nantian",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/chuanbei" : random(2),
        ]));
        set("outdoors", "henshan");
	set("coor/x", -330);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
