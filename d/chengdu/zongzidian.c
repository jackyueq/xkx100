// Room: /d/chengdu/zongzidian.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "�������ӵ�");
	set("long", @LONG
����һ�Һͼ��ˡ�����ի����Ӫ�����ӵꡣ�����������־�˵�Ǻ�
�����ص�һ����������Ϊ���ϵ�����¥��һ����˻����գ����������
�̣�����Ҫ׬ǮΪ����������������������������ϣ����������һ
ֱ���ã�����������ϼ���������Ц�ݡ�
LONG	);
	set("exits", ([		
		"west" : __DIR__"xiaojie1",
	]));
	set("objects", ([
		__DIR__"npc/zhangqinlin" : 1,
	]));
	set("coor/x", -8010);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

