// /yubifeng/zoulang5.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ�����������ȣ�ͨ��������˵����ҡ�����ľ���ϻ���л�
����棬�����Щ��ʱ�˵��ֻ���ÿ���߰˲�������һ����̨��������
�̴�ͭ�������γ�����֮����һ��
LONG);
	set("exits", ([
		"west"  : __DIR__"westroom2",
		"east"  : __DIR__"houting",
		"south" : __DIR__"zoulang3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
