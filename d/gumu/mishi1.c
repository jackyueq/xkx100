// mishi1.c ����
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵƹ�
����ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�������������
���Դ����ҳ�һ˿��϶��
LONG	);
	set("exits", ([
		"out"   : __DIR__"bianhou",
		"north" : __DIR__"mishi2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 20);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

