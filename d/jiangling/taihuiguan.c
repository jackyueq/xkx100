//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "̫�͹�");
	set ("long", @LONG
����ԭ����̫����Ԫ谵�ʮ������ص���������¥ӿ��ۼ׾�����
�˳����䵱���ڸ߸ߵ�ƽ̨����һ��Լʮ�׼����Ľ�����ͭ�ߣ���
��ӳ��֮�£������Ŀ������֮�⣬���ܿ�����
LONG);

	set("exits", ([ 
      "east" : __DIR__"xiaowu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2055);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
