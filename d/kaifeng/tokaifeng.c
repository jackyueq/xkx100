// /kaifeng/tokaifeng.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������ӿ��⸮���������Ĺٵ�����������·�ΰ��Ϻ�
����Ҳ���١�����ͨ�򿪷⣬����ͨ��������
LONG
	);
	set("exits", ([
		"east" : __DIR__"tonanyang",
		"west" : __DIR__"guandao1",
	]));
	set("outdoors", "kaifeng");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
