// Room: /d/wuxi/eastroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
��������ʯ��ֵ���ɨ�øɸɾ��������߾��ǳ����ĵ������㳡�ˣ�
�������У�ʮ�����֡��������������Ե���������࣬������Ϊ����
����������֪�����ţ����Ĺ��Ű��ֳ�����һ���������·���ģ�
һ������֮�����˲��ɵط����������ӿ�Ų����ϱ���פ������������
����һֱͨ���Ӫ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"yamen",
		"south" : __DIR__"zhengbing",
		"east"  : __DIR__"eastroad2",
		"west"  : __DIR__"guangchang",
	]));
	set("coor/x", 380);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}