// Room: /d/wuxi/wuguan.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�߽�����һ���ܴ�����䳡������������ϸɳ��������ú���Ļ��
�������������Ե�ʮ�ֵ�̤ʵ�������½����ĵ��������ؽ�ͷ��ָ����
һ��һʽ����ϰ�����ߵı������Ϸ��Ÿ���ľ�Ƶı���������ȥ������
��ͷ�������ˡ���Ȼ�ؽ�ͷΪ�˱Ƚ���ͣ�������Ҫ�Ƿǵý�ȥ�ҿ���
��Ҳ�Ǻܲ���ò�ġ�
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"west" : __DIR__"wuguan",
		"east" : __DIR__"wuguanwoshi",
	]));
	set("objects", ([
		__DIR__"npc/qin" : 1,
	]));
	set("coor/x", 390);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}