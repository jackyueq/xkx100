//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "Ԫ���");
	set ("long", @LONG
����ԭ������ۣ������ƿ�Ԫ��䣬ԭ���ھ��ݳ���������Ǩ���ˡ�
Ϊ�ܿ����ʵ�����֮���䣬����������Ϊ��Ԫ������ǰһ���Ľ��ܼⶥ
������¥������ʸ󣬺������������ڳ�̨֮�ϣ��������£�Ρ��
ׯ�ϡ�
LONG);
	set("exits", ([ 
      "west" : __DIR__"dongjie1",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
