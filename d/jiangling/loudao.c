//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "¥��");
	set ("long", @LONG
���������ڣ�ʰ����¥���ڰ�������¥�ݷ�����΢��֮֨֨������
��ֻ���鸡���ģ��������ڡ�����¥����������������ް����Ϣ����
��΢���м��������š�
LONG);
	set("exits", ([ 
		"east" : __DIR__"kongwu1",
		"down" : __DIR__"loudi",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2039);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
