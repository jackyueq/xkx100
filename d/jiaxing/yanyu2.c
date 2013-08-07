// Room: /d/jiaxing/Yanyu2.c  ����¥��¥
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;

string look_bian();
int do_halloa(string arg);

void create()
{
        set("short", "����¥��¥");
        set("long", @LONG
����¥���Ϻ��ϣ������ٷ磬�������ˡ�������ҷ�������������
�����̱�����βС�۵�����䡣���ˮ�ﶼ���ű����͵���Ҷ��ԽŮ
��裬�������ǡ�����۹��ͣ��������ޣ��ػ���֮��ֻ���������
(halloa)��

    ¥������һ������(bian)����˿��ߣ��ľΪ������ã�ͩ��
���ᣬ������������������������Щ�ּ���ziji����
LONG );
        set("no_sleep_room",1);
        set("item_desc", ([
            "ziji" : "�����߹ֽа��񴦻�����\n",
            "bian" : (: look_bian :),
        ]));

        set("exits", ([
            "down"     : __DIR__"yanyu",
        ]));
	set("no_clean_up", 0);
	set("coor/x", 1520);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	mapping myfam;
	
	add_action("do_halloa", "halloa");
	myfam = (mapping)me->query("family");
	if (!mapp(myfam) || !stringp(myfam["family_name"])) return 0;
	
	if (myfam["family_name"] == "����ɽ��" && me->query_condition("ice_sting")
		&& me->query_condition("ice_sting") < 10) {
		message_vision(HIB"$Nֻ�������Խ��Խ���״���״�����ޱȣ��ٲ����ξ��������ˣ�\n", me);
		message_vision(HIG"�����ñ���һ��˵������С���ޣ�֪�������˰ɣ�����������ϴ̶���\n", me);
		message_vision("$N����һ������æת��������ֻ��һ�����ˣ�˫�ָ���һ��ʯͷ������Ϊ�㣬\n", me);
		message_vision("�������������������˹��������˹���һ������С�޶���Ҫ���ĸ��������� \n", me);
		message_vision("˵�գ�˫��һ������Խ�����ݶ���$N֪�������˾��ǣ���ϲ��������æ�������ϡ�\n"NOR, me);
		me->move(__DIR__"yanyu3");
	}
}

int do_halloa(string arg)
{
	object me = this_player();
	mapping myfam;
	
	if (!arg || arg != "�常") return 0;
	
	myfam = (mapping)me->query("family");
	
	if (!mapp(myfam) || !stringp(myfam["family_name"])) return 0;
	if (myfam["family_name"] == "����ɽ��" && myfam["master_id"] == "ouyang feng") {
		message_vision(HIC"$N���������Хһ�������常�����������\n", me);
		message_vision("���˰��Σ����ϴ�����Ϥ�ġ������������������죬ŷ�����¥��һԾ���¡�\n", me);
		message_vision("ŷ�������$N���˵�ͷ�����Ժ��ӣ�������ѧ�����ˣ��������ɣ�\n"NOR, me);
		me->move(__DIR__"yanyu3");
		return 1;
	} else  return notify_fail("��Ϻ�׽У����常��˭��\n");
}

string look_bian()
{
        return
        "������������������������������������������������������������������\n"
        "��������������                    ��������������������������������\n"
        "����������������            ��������    ��        ����������������\n"
        "����������                                            ������������\n"
        "������������÷������  ��÷�Ľ���  �������Ӻ�  ˫��ѻ��ɫ����������\n"
        "���������������ںδ�  ˫��ҡͷ��  ��ĺ���ͷ�  �紵����������������\n"
        "�������������¼���ǰ  ����¶����  �����ɲ���  ���Ųɺ�������������\n"
        "��������������������  ��������ͷ  ��ͷŪ����  ��������ˮ����������\n"
        "��������������������  ���ĳ��׺�  �����ɲ���  ����˼�ɺ衡��������\n"
        "�����������ɺ�������  ��¥����¥  ¥��������  ��������ͷ����������\n"
        "��������������ʮ����  ����������  �������Ը�  ��ˮҡ���̡���������\n"
        "������������ˮ������  ���������  �Ϸ�������  ���ε����ޡ���������\n"
        "������������������������������                    ����������������\n"
        "������������������������������������������������������������������\n";
}