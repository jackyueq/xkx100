// Room: /d/henshan/jiayingmen.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ӧ��");
        set("long", @LONG
�����ǵط���ӭ�Ӿ�ʦ��ʷ�����������ĵط�����������������
���ˡ����ϵ���Ҳ�Ͼ�ϸЩ�����ʵ���ʱʱ���¡�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"yubeiting",
           "north"  : __DIR__"yushulou",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1150);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
