// mishi5.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵƹ�
����ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�������������
���Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ���š�
LONG	);
	set("exits", ([
		"west"  : __FILE__,
		"east"  : __FILE__,
		"south" : __DIR__"mishi3",
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", 40);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
