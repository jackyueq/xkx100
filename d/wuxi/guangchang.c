// Room: /d/wuxi/guangchang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����㳡");
	set("long", @LONG
���������������ģ�һ���ܿ����Ĺ㳡�������úܴ���������ʯ
�̳ɣ���������Ϊʲô��������������ȴû��˵�������ˡ�һЩ���ֺ�
�е������������������Կ������������Ը��ص���������������
�����������У�һ�ɷ����������ߺ�������֣���������Щ�ྲ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"northroad1",
		"south" : __DIR__"southroad1",
		"east"  : __DIR__"eastroad1",
		"west"  : __DIR__"westroad1",
	]));
	set("coor/x", 370);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}