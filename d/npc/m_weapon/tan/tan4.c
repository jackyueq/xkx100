//tan4.c

inherit ROOM;

void create()
{
	set("short", "�����Ϻ� ");
	set("long",
		"�����Ǽ����Ϻ��ף����ܺں����ģ�ͷ���Ͽ�����һ�����⣬��ߵ�ˮ��\n"
		"���Ϻ��µ�ӿ���š���������һ�����ۡ������ƺ���һ�����⣬Ҳ��֪��Щ\n"
		"ʲô����ΧһƬ���ţ��ƺ������Ų��ɱ����\n"

	);
	set("exits", ([
		"up"   : __DIR__"tan2",	
		"down" : __DIR__"tan5",
		"southwest" : __DIR__"tan6",
		"northwest" : __DIR__"tan6",
		
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -1010);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
