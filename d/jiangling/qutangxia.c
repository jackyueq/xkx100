//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����Ͽ");
	set ("long", @LONG
�Ÿ�����ʫ��д�������׵۸�Ϊ��Ͽ�������չ����ιء����Ӱ�
�۳��򶫣�����볤����Ͽ�������������Ͽ������������Ͽ�ʹ�Ͽ
����ˮϿ������Ͽ����̣�ȴ��Ϊ��ΰ�վ���
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"baidicheng",
		"east" : __DIR__"wuxia",
	]));
  
	set("coor/x", -1510);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
