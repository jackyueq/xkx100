//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��Ԫ��");
	set ("long", @LONG
һ��������Ժ����˵���в���ӡ�ȡ�˹����������顢̩�����ձ�
�ȹ������ķ𾭣�������ľΤ�Ե��񡢰����������޺����ǧ�ֹ�
����ȱ��
LONG);
	set("exits", ([
		"west" : __DIR__"hzjie5",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
