// buwei3.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻ�ɽ�����ĺ��á�����һ������д�š������������ĸ����֣�
���ϲ������£���������һ����������������ڣ�����¾ɣ����ǻ�ɽ
��ǰ������ʦ���彣����ɽ�ɽ�������������ô�����������֪������
���ټ�а������ɥ������Щǰ����ʦ�ĳ���֮�¡������񰸵�ǽ���ǻ�
ɽ�ɿ�ɽ��ʦ����ʦ�Ļ��󡣻��������������ǳ�����������¯��
�����������㣬��������������ɢ����һ��̴��ζ������������ͨ����
���������
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"buwei1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("huashan")+"/first": 1,
	]));
	set("valid_startroom","1");

	set("coor/x", -850);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
	"/clone/board/huashan_b"->foo();
	replace_program(ROOM);
}
