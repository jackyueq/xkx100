//ROOM: /d/yanziwu/dannuo.c

inherit ROOM;
void create()
{
	set("short", "�Ŵ��");
	set("long",@LONG
����һ�����µĴ��������ϰ��ż�����̴ľ�������������Ʋ;�һ
Ӧ��ȫ������һ���绨ľ�Ρ�ÿ��Ľ�����Һܶ��˶��ڴ��ò͡�
LONG );
	set("exits", ([
		"west" : __DIR__"yimen",
		"east" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}