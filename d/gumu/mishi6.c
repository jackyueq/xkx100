// mishi6.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵƹ�
����ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�������������
���Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ����
LONG	);
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"north" : __DIR__"mishi3",
		"south" : __DIR__"mishi7",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", 20);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
