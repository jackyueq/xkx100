// skybook.c

#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
void create()
{
	set_name(HIB"��������"NOR, ({"skybook","book"}) );
	set_weight(10);
	set("no_steal", 1);
	set("no_beg", 1);
//	set("no_get", 1);
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
	if (!present(this_object(), this_player())) return 0;

	tell_object(me,
    "�����		    ����
���(cloud)	 ����ȥ�ĵط�\n");
	return 1;
}
// ���

int cloud_goto(string arg)
{
	object obj,mme=this_player();
	object* ob;
	int i;
	ob = users();

	if (!present(this_object(), this_player()))
		return 0;

	for ( i=sizeof(ob); i>0; i-- )
	{
		if ((ob[i-1]->query("id")==arg) && ( !wizardp(ob[i-1])))
		{
			obj = environment(ob[i-1]);
			this_player()->move(obj);
			tell_object(mme,HIM"��һ����������,ֻ����ǰ���Ʒɹ�,���߷�������� ..\n\n"NOR);
			tell_object(mme,"���,��ʹ��,��ˬ,ˬ����!\n\n");
			mme->move(obj);
			tell_object(mme,"������ƻ����½�,��ߴһ��,��!��ȫ��½...\n");
			return 1;
		}
	}
	return 0;
}

void owner_is_killed()
{
	write(HIY"ֻ����ǰ���һ��...������.....\n"NOR);
	destruct(this_object());
}
