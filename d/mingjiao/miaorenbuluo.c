//miaorenbuluo.c

inherit ROOM;

void create()
{
	set("short", "���˲���");
	set("long", @TEXT
����ǰͻȻһ����ԭ�����߽���һ�����˲��䡣������Χ���ڻ��
�ߣ���ɫ�ϣ���������ĳ�ּ�����ʽ��������ʿ������ľ�ۣ�������
���дʡ�ͻȻ�����Ǻ��������㡣
TEXT );
	set("outdoors", "mingjiao");
 	set("exits",([
		"north" : __DIR__"westroad2",
	]));
	set("objects",([
		"/d/mingjiao/npc/miaozuwushi":4,	
	]));
	set("coor/x", -31000);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}