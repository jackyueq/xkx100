inherit ROOM;
 
void create()
{
	set("short", "С·");
	set("long",@LONG
����һ��С��������������Զ�����졣С��������ֲ��һЩ�һ�����
��ֻһƳ�ͷ��֣���Щ�һ�ȫ�ǰ�ɫ�ġ�
LONG );
	set("exits", ([
		"east" : __DIR__"road2",
		"west" : __DIR__"taohua1",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"taohua1",
	]));
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	set("coor/x", 9100);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
       	replace_program(ROOM);
}