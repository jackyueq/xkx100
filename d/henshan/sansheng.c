// Room: /d/henshan/sansheng.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������Ǹ����¿�ɽ��ʦ��˼��Ǵ�����˵��˼��ʦ�����������
����ʳ�����������Զ���п����ӣ���˵���ܽ��ڻ�˼��ʦ������ǧ
�꣬��ͤͤ���ǣ�������ԡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"   : __DIR__"jigaoming",
           "eastdown"  : __DIR__"fuyansi",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1070);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
