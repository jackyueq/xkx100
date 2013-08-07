// skybook.c

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;


void create()
{
	set_name(HIY"��������"NOR, ({"skybook","book"}) );
	set_weight(10);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_get", 1);
	set("no_drop","�ۣ����鶼�붪��,С������Ǵ��\n\n");
	set("long",@LONG
���˵�����������"����"�ı���,��Ϊ������ʶ��,����ʩ�˷�,
������������������,�Ǻ�!������äҲ�ܶ���,�쿴��(kan)�ɣ�
LONG );
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("material", "unknow");
	}
}

void init()
{
	add_action( "kan_book", "kanbook" );
	add_action( "bigu_eat", "bigu" );
	add_action( "cloud_goto", "cloud");
}

int query_autoload()
{
	return 1;
}

//����
int kan_book()
{
	object me;
	me=this_player();
	if (!present(this_object(), this_player()))
		return 0;

	tell_object(me,
    "�����		    ����

�ٹ�(bigu)        ������ҹ���Բ���\n

����(body)        ����ָ���������\n

���(cloud)     ����ȥ�ĵط�\n");
	return 1;
}

// �ٹ�

int bigu_eat()
{
	object  ob, me;
	int	     fw;

	ob = this_object();
	me = this_player();

	if (!present(this_object(), this_player()))
		return 0;

	if( !me->query_condition("f_condi") )
	{
		write(HIY"����������д�,����������...\n"NOR);
		tell_object(me, "��ֻ��������ˬ,���Բ��Է���...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);

		write("������ҹҲ������ˣ�\n\n");
		me->apply_condition("f_condi", 5);
		ob->set("eated", "xixi");
	}
	else
	{

		tell_object(me, "Ou��������˸����á�����Ou...Ou...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);
	}

	return 1;
}
// ���

int cloud_goto(string arg)
{
	string home;
	object mme;
	int goto_inventory = 0;
	object obj;
	string msg;
	mme=this_player();
	if (!present(this_object(), this_player()))
		return 0;

	if( !arg ) return notify_fail("��Ҫȥ���\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail("��Ҫȥ���\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !mme->visible(obj)) {
		arg = resolve_path(mme->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return mme->move(arg);
			return notify_fail("û�������ҡ������ط���\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("������û�л������� goto��\n");
	tell_object(mme,HIM"��һ����������,ֻ����ǰ���Ʒɹ�,���߷�������� .
.\n\n"NOR);
	tell_object(mme,"���,��ʹ��,��ˬ,ˬ����!\n\n");
	mme->move(obj);

	tell_object(mme,"������ƻ����½�,��ߴһ��,��!��ȫ��½...\n");
	return 1;
}
// �ָ�
int body_recover()
{
    object mme;
    mme=this_player();
    mme->set("jing",mme->query("max_jing"));
    mme->set("eff_jing",mme->query("max_jing"));
    mme->set("qi",mme->query("max_qi"));
    mme->set("eff_qi",mme->query("max_qi"));
    mme->set("neili",mme->query("max_neili"));
    tell_object(mme,"���,̫����,�����ȫ��������!\n");
    return 1;
}
void owner_is_killed() {

	write(HIY"ֻ����ǰ���һ��...������.....\n"NOR);
	destruct(this_object());
}
