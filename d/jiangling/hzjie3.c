//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG
�����人����Ľֵ����Ӵ��ϱ����ĸ�ɫ�˵ȣ�����������Ħ
����ࡣ����һ����������ڷ�������ջ�������̺죬����̾Ϊ��ֹ��
��������������̨��
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"qintai",
		"west" : __DIR__"juhuahui",
		"south": __DIR__"hzjie4",
		"north": __DIR__"hzjie2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}