//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��ũ��");
	set ("long", @LONG
����һƬ���Ӳ�����ɽ�룬��Բ��ǧ��ഫ�Ϲ�ʱ��ũ��������
��鳢�ٲݣ���ǧ�嶸�ͣ����ܲ�ҩ���ʵá���ũ�ܡ�������������
ɼ������������������������ܲ���ҩ�ݱ�أ�Ұ����׺������ʱ�֡�
���͵����У��ɼ�ɽ���������ƣ����л�ѩ���ǡ�
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
                "east" : __DIR__"longzhong",
                "south": __DIR__"shandao6",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
