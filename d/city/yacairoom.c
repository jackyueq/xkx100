// yacairoom.c.
// Last modified by winder 2002.11.11

inherit ROOM;

void create ()
{
	set("short", "Ѻ�ʷ�");
	set("long", @LONG
�������һ�����������м����һ�����̡��Ŀ������۾��������
�ġ���ϯ��һλ���ӣ����ﲻ����Ū��һ�������������������ׯ����
    ǽ�Ϲ���һ����(bian)��
LONG);

	set("item_desc", (["bian" : "
ya tc <����> <coin|silver|gold> Ѻͷ��(����˳�򼰵�������ȷ)       һ��ئ��
ya dc <����> <coin|silver|gold> Ѻ���(����������ȷ)               һ��ʮ��
ya sd <����> <coin|silver|gold> Ѻ˫��(������ͬ�Ҿ�Ϊż��)         һ��ʮһ
ya kp <����> <coin|silver|gold> Ѻ����(������ͬ�Ҿ�Ϊż��)         һ����
ya qx <����> <coin|silver|gold> Ѻ����(����֮��Ϊ��)               һ����
ya dd <����> <coin|silver|gold> Ѻ����(������Ϊ����)               һ����
ya sx <����> <coin|silver|gold> Ѻɢ��(����֮��Ϊ�����塢�š�ʮһ) һ���
ÿ�̰����ϵ��µ�˳��ֻ����һ�ֵ���(ͷ�ʺʹ�ʿ�ͬʱ����)�������������ׯ��Ӯ��
"
	]));
	set("exits", ([
		"west" : __DIR__"shaiziting",
	]));
	set("objects", ([
		__DIR__"npc/zhuangjia" : 1,
	]));

	set("no_fight", 1);
	set("no_beg", 1);
	set("no_magic", 1);
	set("no_clean_up", 1);
	set("coor/x", 22);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
