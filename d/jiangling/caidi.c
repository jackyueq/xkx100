//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ��˵أ�����һƬ���̣��������˿��Ĳˡ���ɫ�Ķ���ڲ�
�������·��衣�����Ĳˡ�������һ����Ѱ�����߲ˣ������ֳ����˾�
�����ǿյġ�����ȡ������ºţ�����Ц��ֱ��ֱ����û������µ���
˼��
LONG );
	set("exits", ([
		"west"     : __DIR__"maxipu",
	]));
	set("objects", ([
		__DIR__"npc/diyun" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1600);
	set("coor/y", -2210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}