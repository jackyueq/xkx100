// mishi2.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵƹ�
����ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�������������
���Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ���ơ�
LONG	);
	set("exits", ([
		"east"  : __DIR__"mishi3",
		"west"  : __FILE__,
		"north" : __FILE__,
		"south" : __DIR__"mishi1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 30);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
