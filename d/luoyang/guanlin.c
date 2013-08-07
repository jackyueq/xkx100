// Room: /d/luoyang/guanlin.c
// Last modified by winder 2002.11.11

#include <ansi.h>;
inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
�˴�λ����������ʮ���ﴦ������ʼ�����ƣ��ഫΪ�����񽫹���
�׼�����أ�ǰΪ������ΪĹڣ��ڣ���������࣬ǧ������أ�ε
Ȼ���֣��ʳơ����֡������������ʼ����ֲ�ɡ���Ǭ¡ʱ�ּ�������
�³��ֽ�Ĺ�ģ�����������Լ��Ķ���ң��������ӹ�¥����ǽ���ߣ�
��������������������������й����ŵ���װ�񣬶���Ϊ��װ�񣬶���
Ϊ����˯��������Ϊ�����С�����񣬴��ǰ���и��ư�ʮ������
���������µ�һ�ѡ��Űز����������ûʣ�¡ڣ�ޱ������顰��������
��ʥ��ۡ���������Ȼ��
    ���н�����ʿ���˰ݼ���
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"      :  __DIR__"road4",
	]));
	set("objects",  ([
		__DIR__"obj/xiang" : 1,
	]));
	set("no_fight", 1);
	set("no_beg", 1);
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_ketou","ketou");
	add_action("do_ketou","kneel");
}

int do_ketou()
{
	object *inv, pai, me = this_player();
	string partynm;
	int i, j, mylvl, oblvl;

	if(!me->query("party"))
		return notify_fail("�㲻�����κΰ�ᣡ\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�������ȡ���ƣ�\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	inv = all_inventory(me);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai")
			return notify_fail("�㹧�������ؿ���ئ��ͷ��һ�����Ҳû�У�\n");
	}
	message_vision(HIG"$N��ϥ���£�һ����ͷ�����ؿ�����ȥ����Ȼ�䣬һ����εض�����ֻ����ž����һ������֦�ϵ���һ�����ƣ�������$N���Ҳ��֪�����ĸ���Ƥ���������ġ�\n"NOR, me);
	pai = new("/d/luoyang/obj/yaopai");
	pai -> move(me);
	return 1;
}
