//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG
�����人����Ľֵ����Ӵ��ϱ����ĸ�ɫ�˵ȣ�����������Ħ
����ࡣ������һ���ӻ��꣬������һ����Ժ��
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"guiyuansi",
		"west" : __DIR__"zahuodian",
		"north": __DIR__"hzjie4",
		"south": __DIR__"tulu1",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
