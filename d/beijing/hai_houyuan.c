// /beijing/hai_houyuan.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι�����Ժ");
	set("long", @LONG
�����Ǻ��ι�����������һ��С��԰�����ҵ����Ÿ��ֻ��ݣ���
�����˴����Ӳ��Ѿ����úܸ��ˡ�һЩ�ʻ������ڲݴ��У�������
���ϵ�Ʈ����
LONG );
	set("exits", ([
		"north" : __DIR__"hai_dating",
	]));

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("coor/x", -230);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
