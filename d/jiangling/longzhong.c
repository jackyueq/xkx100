//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��¡��");
	set ("long", @LONG
����һ��С��ׯ����������Ⱥɽ�������ɰز��죬Ϫ�����ƣ���ɫ
�������ഫ���������ʧȥ˫�ף�ʮ���������常����������������ӣ�
���������
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"shennongjia",
		"south": __DIR__"shandao3",
	]));
  
	set("coor/x", -1510);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}