// /kaifeng/fenjiao.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
һ�ɳ�ζ�˱Ƕ�����һ�ѽ�ͷ��ӬΧ�Ÿ�С���Ӳ��ϴ�ת�����Ǹ�
����ɮ����������˵ص�С����ӣ���Ȼ�ǱȽϲ������㻹�ǸϿ��߿�
Щ�ɣ���С�Ļ����ȥ�ġ�
LONG);
	set("objects", ([
		__DIR__"npc/popi" : 1,
		__DIR__"npc/wulai" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"maofang",
		"north" : __DIR__"kongdi",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
