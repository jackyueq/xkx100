// Room: /d/nanyang/jiulou1.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "ӭ��¥");
	set("long", @LONG
��Բ������������ӭ��¥����˵�����˲�֪�����˲�����������
ѧʿ���ε��ˣ���ӭ��¥�������޲����ڣ���ȻΪ�����ң�����һ��
���麣�ڵļѻ����Ӵ�ӭ��¥��������¥�²��ü��ף��˿Ͷ��Ǵ�
�ҵ����ˣ������ӣ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG );
	set("exits", ([
		"west" : "/d/kaifeng/tonanyang",
		"east" : __DIR__"nanyang",
		"up"   : __DIR__"jiulou2",
	]));
	set("objects", ([
		__DIR__"npc/xiao-er2" : 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("coor/x", 0);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
