// Room: /d/wuxi/southroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
�ϳ������ǳ���ķ����ضΣ�����һ�ɵƺ���̡�Ц������������
�������������һƬ����������У��㲻����Գ����������һ������
�Ĺ㳡��������һ�����ֺŵ��ӻ��̣������򴫳�һ�����˵ľ���������
���ǽ����������ɺ�¥�����湩Ӧ���������ŹǸ��������ܱߣ��ϱ���
�����˺ӣ������ź�����ϡ�
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"south" : __DIR__"sanfengqiao",
		"north" : __DIR__"guangchang",
		"east"  : __DIR__"songhe",
		"west"  : __DIR__"zahuopu",
	]));
	set("objects", ([
			__DIR__"npc/lady1" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}