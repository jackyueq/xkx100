// /kaifeng/road1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ϱ������������ţ�������ӯ�ţ�����ǰ���ϳ�Ѳʱ��
�ߵĵ������޵�Ҳ�Ǹ���ƽ���������ߵ��̲��ϡ������ٹ�ȥ��Զ����
��ʯ���ž�������£���������ȸ�š�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"    : __DIR__"yaopu",
		"north"   : __DIR__"zhuque",
		"southup" : __DIR__"gongmen",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
