// houyuan.c
inherit ROOM;

void create()
{
	set("short", "��͵��Ժ");
	set("long", @LONG
��������͵��Ժ��Ժ������Щ��ˡ�ǽ����һ��ˮ��(well)��վ
��ˮ�������¿���ֻ������ף����������ǻ��������̦��һ�����
����һ������������ϵ��һ��ľͰ��������һ�����ȣ�ͨ�����ŷ���
LONG
	);
	set("outdoors", "huanggong");
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"yushanfang",
	]));
	set("item_desc", ([
		"well" : "һ�ڿݾ����ഫ����ȥ�������ݡ�\n"
	]));

	set("coor/x", -180);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}