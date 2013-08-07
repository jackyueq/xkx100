// Room: /d/taohua/shui.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", BLK HBWHT"ˮ"NOR);
	set("long", @LONG
���������в��ˮ����һ�����������ϵ����ݾͱ������ˡ����в�
�Ĺ��ֻ�����ͨ����������ʧ�˷���ÿһ�����������еĹ�ϵ������
�������ˡ����ˡ�
LONG
	);
	set("exits", ([ 
		"tu" : __DIR__"tu",
		"huo" : __DIR__"huo",
		"mu" : __DIR__"mu",
		"jin" : __DIR__"jin",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", -10);
	setup();
}

void init()
{
	mixed *local;
	string tempstr;
	object me = this_player();
	int *month_map = ({2,2,-1,-1,-1,-1,1,1,1,1,2,2});

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("liangyi")) 
		me->set_temp("liangyi", -1);
	if (!me->query_temp("sixiang")) 
		me->set_temp("sixiang", -1);
	if (!me->query_temp("wuxing")) {
		local = localtime(time());
		me->set_temp("wuxing", month_map[local[LT_MON]]);
		me->set_temp("wuxing_total", 12);
		me->set_temp("wuxing_step", 1);
		me->set_temp("wuxing_error", 1);
		tempstr = "����";
		if (me->query_temp("liangyi") < 0) tempstr += "�������";
		if (me->query_temp("sixiang") < 0) tempstr += "��������";
		if (me->query_temp("wuxing") < 0) tempstr += "��̤����";
		me->set_temp("last_damage_from", tempstr + "���������л��ض�����");
	}
	if (me->query_temp("sixiang") < 0 || me->query_temp("liangyi") < 0) 
		me->set_temp("wuxing", -1);
	if (me->query_temp("wuxing_error") >= 12) {
		tempstr = "������";
		if (me->query_temp("liangyi") < 0) tempstr += "������ǡ�";
		if (me->query_temp("sixiang") < 0) tempstr += "��������";
//		if (me->query_temp("wuxing") < 0) tempstr += "��̤����";
		write(tempstr + "��̤���У���һ�ɴ���˦����������ˤ��ɽ���µ�һ����ʯ�ϣ�\n"); 
		me->delete_temp("wuxing");
		me->delete_temp("liangyi");
		me->delete_temp("sixiang");
		me->delete_temp("wuxing_total");
		me->delete_temp("wuxing_step");
		me->delete_temp("wuxing_error");
		me->unconcious();
		me->move(__DIR__"shore", 1);
		return;
	}
	if (me->query_temp("wuxing_step") >= me->query_temp("wuxing_total")) {
		write("�㽫����̤�飬���ڴ��������󣬴Ӹ�̨�ײ����˳�����\n"); 
		me->delete_temp("wuxing");
		me->delete_temp("liangyi");
		me->delete_temp("sixiang");
		me->delete_temp("wuxing_total");
		me->delete_temp("wuxing_step");
		me->delete_temp("wuxing_error");
		me->move(__DIR__"tomb", 1);
		return;
	}
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

int valid_leave(object me, string dir)
{
	int wuxing = me->query_temp("wuxing");

	if (dir == "tu" || dir == "huo" || dir == "mu" || dir == "jin") {
		if (wuxing < 0) {
			write("���л��غ�Ȼ������������â��â�������㣬��ֻ��ȫ��ʹ������ʶҲ��Щģ���ˣ�\n");
			me->receive_wound("jing", 50);
			me->receive_wound("qi", 50);
			me->add_temp("wuxing_error", 1);
		}
		else {
			switch (dir) {
				case "huo":
					if (wuxing == 1) {
						write("���л��غ�Ȼ������һ����â�������㣬��ֻ��һ��ʹ����\n");
						me->receive_damage("qi", 40);
						me->add_temp("wuxing_error", 1);
					}
					else
						me->add_temp("wuxing_step", 1);
					break;

				case "jin":
					if (wuxing == 1) {
						me->add_temp("wuxing_total", 1);
					}
					else {
						write("���л��غ�Ȼ������������â��â�������㣬��ֻ��ȫ��ʹ������ʶҲ��Щģ���ˣ�\n");
						me->receive_wound("jing", 40);
						me->receive_wound("qi", 40);
						me->add_temp("wuxing_error", 1);
					}
					break;

				case "tu":
					if (wuxing == 1) {
						write("���л��غ�Ȼ������������â��â�������㣬��ֻ��ȫ��ʹ������ʶҲ��Щģ���ˣ�\n");
						me->receive_wound("jing", 40);
						me->receive_wound("qi", 40);
						me->add_temp("wuxing_error", 1);
					}
					else {
						me->add_temp("wuxing_total", 1);
					}
					break;

				case "mu":
					if (wuxing == 1) 
						me->add_temp("wuxing_step", 1);
					else {
						write("���л��غ�Ȼ������һ����â�������㣬��ֻ��һ����ѣ��\n");
						me->receive_damage("jing", 40);
						me->add_temp("wuxing_error", 1);
					}
					break;
			}
		}
	}
	
	return ::valid_leave(me, dir);
}
