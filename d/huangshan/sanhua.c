// Room: /d/huangshan/sanhua.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "ɢ����");
	set("long", @LONG
ɢ��������һ��ȣ����з��Ͳβ�ʼܷ壬����ʯ�ȴ�����䣬
Զ�۷��͵��֣����˹�ʯ���ɡ�ÿ������֮��������ʢ�������Ƿ�����
����������Ů����Ϊ���ޡ��˻��Ű꣬������ű鲼ɽ�룬����עĿ��
�ʳơ�ɢ���롱�������֮�Q��ʫ��Ի����������Ůɢ�컨��ԭ���춼
���Ӽҡ�һ�뻨������ȣ�������ʵ�봺������
    ������������Ĺ�ʯ�α�������
LONG
	);
	set("exits", ([ 
		"west"      : __DIR__"paiyun",
		"east"      : __DIR__"mengbi",
		"northeast" : __DIR__"shisun",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
