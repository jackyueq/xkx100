// jinshe2.c 

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
	add_action("do_du", "du");
	add_action("do_du", "study");
}
void create()
{
	set_name(YEL"��������ܸ��"NOR"�в�", ({ "jinshe book2","book2", }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "paper");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("no_put", "�����������ܷ����Ƕ���\n");
		set("long",
	"����һ���ñ�ֽд�ɵ��顣���飺��������ܸ����\n"
	"��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n", );
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 
	int neili_lost;

	if (!(arg=="jinshe book2" || arg == "book2"))
	return 0;
	if (!present(this_object(), this_player()))
		return 0;
	if (where->query("pigging")){
		write("�㻹��ר�Ĺ���ɣ�\n");
		return 1;
	}
	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("���޷���ս����ר�������ж���֪��\n");
		return 1;
	}
	if (!id(arg)) {	
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( !me->query_skill("literate", 1) ){
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}
	message("vision", me->name() + "��ר�ĵ��ж�������ܸ��\n", environment(me), me);
	if( (int)me->query("jing") < 25 ) {
		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}
	neili_lost = 5;
	if( (int)me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
		return 1;
	}
	pxlevel = me->query_skill("jinshe-zhui", 1);
	if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
		write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
		return 1;
	}
	if( me->query_skill("jinshe-zhui", 1) > 199){
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1;
	}
	me->receive_damage("jing", 15);
	me->set("neili",(int)me->query("neili")-neili_lost);
	me->improve_skill("jinshe-zhui", (int)me->query_skill("literate", 1)/3+1);
	write("���ж�������ܸ�������ĵá�\n");
	return 1;
}

