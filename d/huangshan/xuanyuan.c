// Room: /d/huangshan/xuanyuan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "��ԯ��");
	set("long", @LONG
���ǻ�ɽ��ɽ������߷壬��һ·��ʯ��ᾣ���֮ǰ���ʯ���쳣
���У����Ժ������̡���˵������ǻƵ۵õ����������ڣ�Ҳ��֪���
�������������������ż����ɼ�ȷ�����ڴ��޵���
LONG
// �ϱ���һ���壬�����Ȼ��Լ��һé®���ƺ����˾�ס������֮�����һ��������
	);
	set("exits", ([ 
		"west" : __DIR__"caishi",
//		"east" : __DIR__"tiesuo",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
