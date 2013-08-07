// Room: /d/taohua/sixiang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "����");
	set("long", @LONG
����������㣬��һ�����������ϵ����ݾͱ������ˡ���ν����
ϵָ�����仯����̬���༴̫����������̫��������������������ת��
����ʽ�������е�������̫���������д�������������ͬ����Ҳ��̫��
�������������һ���ݻ��������������ԣ��Է�λ��ת�����ۣ�̫��֮
��ΪǬ�������ϣ�̫��֮��Ϊ����������������֮��Ϊ�룬�Ӷ�������
��֮��Ϊ�����������������ֶ�Ӧ�����е����ޣ������Ҿ����룬��ʾ
�����е���ͳ�����������ޡ��Է�λ�����У�������֮�Σ��лƣ���һ
������ֱͨ�·��������켺����
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"taiyin",
		"south" : __DIR__"taiyang",
		"west" : __DIR__"shaoyang",
		"east" : __DIR__"shaoyin",
		"down" : __DIR__"tu",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}