// mishi3.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵƹ�
����ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�������������
���Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩͼ�Ρ�
LONG	);
	set("exits", ([
		"west"  : __DIR__"mishi2",
		"east"  : __DIR__"mishi4",
		"north" : __DIR__"mishi5",
		"south" : __DIR__"mishi6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", 30);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
