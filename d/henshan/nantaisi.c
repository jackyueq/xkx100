// Room: /d/henshan/nantaisi.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��̨��");
        set("long", @LONG
��̨��Ϊ�������滳�õĵ���ʯͷϣǨ�ĵ������������Ʒ�����ʯ
ͷ����Ĺ����������е�������ͨ�ģ�Ȫ�����ˣ�����׷ɣ�ɽ�紵��
ʱ��ҶϤ�������ȥ����
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"shanlu9",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1090);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
