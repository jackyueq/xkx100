// yuhuayuan.c ����԰

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
�����ǻ����ͻ�������԰. ƽ�������ʱ���������, �͹�������
һ���ͻ�Ʒ��. ����, �����ƽ��̫��, ������������. ����Ĺ�Ů��
����������, ��ͨ������. �����Ĺ�, ��Ŀ�����ƽ�����, ����ϸ�ֱ�, 
��ȻƷĿ��ȫ, ������õ�, �������붼�������, ���ﶼ����. ��
������Щ�ʼ���ʵ��϶���.
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"north" : __DIR__"yuhuayuan2",
		"south" : __DIR__"kunningmen",
		"northeast" : __DIR__"fubiting",
		"northwest" : __DIR__"chengruiting",
		"southeast" : __DIR__"wanchunting",
		"southwest" : __DIR__"qianqiuting",
	]) );
	set("objects", ([
		__DIR__"npc/gongnv" : 2,
		__DIR__"obj/panlonghuai" : 1,
		__DIR__"obj/wolongsong" : 1,
		__DIR__"obj/luohanbai" : 1,
	]) );
	set("coor/x", -200);
	set("coor/y", 5330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}