// Room: /city/heyuan.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
��Ա���޵ĺ�԰�����ݳ�����һ�����ĺ�԰�֣����Ǵ�������Ҳ��
��Щ������԰�ڼ�ɽˮ�ش������£�һ��һľ����߽��ģ�����ϸ΢֮
��ȴ��������ͨ��֮�С���Ŀ�������˱Ƿ��㣬��������
LONG );
	set("outdoors", "yangzhouw");
	set("exits", ([
		"north" : __DIR__"caohenanjie",
		"south" : __DIR__"heyuanhouyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -51);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}