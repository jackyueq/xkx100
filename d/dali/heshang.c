//Room: /d/dali/heshang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���������ι�������ˮ֮�ϰٶ�ߵĿ��С�����һ����������
��֮���ţ������ִ��������һ������Ʒ�����Σ��Ų�����һ������
��������������Ԯ�����������գ�ʵ���ϵ�Ҳ��ʮ�����ѡ�һ��ɽ��
Ю�Ž��¼����ɽ���ˮ����������е�һ���⡣
LONG);
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"cangshanlu1",
	    "west"      : __DIR__"hebian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -46000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	if (me->query_dex()<25)
	{
		tell_object(me,"���������¿���һ�ۣ���Ȼ���ˡ�\n");
		me->unconcious();
	}
	return 1;
}