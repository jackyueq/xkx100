inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
��������������ֵľ�ͷ��������һ�������ûʵĴ�¥���Ŷ�����
��һ�����ң�д�š������������ĸ����֣����ǿ����ʵ��ױʡ�����ͨ
���ذ��š�
LONG );
        set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"di_an1",
		"south" : __DIR__"wangfu2",
		"north" : __DIR__"kang1",
	]));
	set("coor/x", -180);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
