inherit ROOM;
 
void create()
{
	set("short", "С·");
	set("long",@LONG
����һ��С��������������Զ�����졣С��������ֲ��һЩ�һ�����
��ֻһƳ�ͷ��֣���Щ�һ�ȫ�ǰ�ɫ�ġ�
LONG);
	set("exits", ([
		"west" : __DIR__"road1",
		"east" : __DIR__"road3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taohua");
	set("coor/x", 9100);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}