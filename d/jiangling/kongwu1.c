//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{

	set ("short", "����");
	set ("long", @LONG
���пտն���������һ����һ�Ρ�һ��֮�⣬ʲô����Ҳû�С���
�Ϲ���һ���Ĳ������ӣ�һ��������һ���������ű߷���һ˫�಼Ů
Ь��ֻ����һ˫ŮЬ�����Ե��ⷿ��ԭΪһ��Ů����ס��
LONG);

	set("exits", ([ 
		"west" : __DIR__"loudao",
		"north": __DIR__"kongwu2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2039);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
