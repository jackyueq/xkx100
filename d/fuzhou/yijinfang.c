// Room: /d/fuzhou/yijinfang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "�½���");
	set("long", @LONG
����ͨ����δ��������(1119��1125��)½�̡�½���ֵܾ��ڴ�
�أ����ֵܲŻ����ͣ�����һʱ��½�̹��θ���֪�ݣ�½�����Ȫ��֪
�ݣ����˻���ʱ���˷�Ϊ��馽����������δ������(1174��1189��)��
�������ν������̣����ݺ�Ҳ���ڴ˵أ���馽�����Ϊ�½�����ʾ�½�
����֮�⡣ 
LONG );
	set("exits", ([
		"east"    : __DIR__"nanhoujie1",	
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1833);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
