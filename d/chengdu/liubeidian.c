// Room: liubeidian.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���������������������й��ź����ҵۣ��߿���������ȴû��
�����ν "��������" �İ����ɡ�����������ı��������ȵ��ܺ�Ӣ��
ͬ�룬���˲�ʤ���ꡣ
    �������������Ƶȵ��佫�Ⱥͽ���Ϊ�׵��ĳ��ȡ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"wuhouci",
		"northup"   : __DIR__"zhugeliang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -3010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
