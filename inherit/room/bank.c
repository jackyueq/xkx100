// bank.c

inherit ROOM;

string money_str(int amount);
void pay_player(object who, int amount);
int do_convert(string arg);
int do_deposit(string arg);
int do_check();
int do_withdraw(string arg);

void init()
{
   add_action("do_convert", "convert");
   add_action("do_deposit", "deposit");
   add_action("do_check", "account");
   add_action("do_withdraw", "withdraw");
   add_action("do_convert", "duihuan");
   add_action("do_deposit", "cun");
   add_action("do_check", "check");
   add_action("do_withdraw", "qu");
}

int do_convert(string arg)
{
   string from, to;
   int amount, bv1, bv2;
   object from_ob, to_ob;

   if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
     return notify_fail("ָ���ʽ��convert <����> <��������> to <��������>\n");

   if( this_player()->is_busy() )
       return notify_fail("��������æ����...��\n");

   from_ob = present(from + "_money", this_player());
   to_ob = present(to + "_money", this_player());
   if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
     return notify_fail("����һ���һ��Ǯ��\n");

   if( !from_ob )     return notify_fail("������û�����ֻ��ҡ�\n");
   if( amount < 1 )   return notify_fail("�һ�����һ������Ҫ�һ�һ����\n");
     
   if( (int)from_ob->query_amount() < amount )
     return notify_fail("������û����ô��" + from_ob->query("name") + "��\n");

   bv1 = from_ob->query("base_value");
   if( !bv1 ) return notify_fail("���ֶ�����ֵǮ��\n");

   bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" );

   if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
   if( amount==0 )   return notify_fail("��Щ" + from_ob->query("name") + "�ļ�ֵ̫���ˣ�������\n");
   this_player()->start_busy(3);

   if( !to_ob ) {
     to_ob = new("/obj/money/" + to);
     to_ob->move(this_player());
     to_ob->set_amount(amount * bv1 / bv2);
   } else
     to_ob->add_amount(amount * bv1 / bv2);

   message_vision( sprintf("$N������ȡ��%s%s%s������%s%s%s��\n",
     chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
     chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
     this_player() );
        if( (int)from_ob->query_amount() == amount )
             destruct(from_ob);
        else
           from_ob->add_amount(-amount);

        this_player()->save();

   return 1;
}


int do_deposit(string arg)
{
   string what;
   int amount;
   object what_ob, me;

   me = this_player();

   if(!arg || sscanf(arg, "%d %s", amount, what) !=2)
   {
     return notify_fail("�����ʽ��deposit <����> <���ҵ�λ>\n");
   }

   if( this_player()->is_busy() )
       return notify_fail("��������æ����...��\n");


           what_ob = present(what + "_money", me);
        if (!what_ob)
        {
                return notify_fail("������û�д�����Ǯ��\n");
        }
        if (amount < 1)
        {
     return notify_fail("��������" + what_ob->query("name") + "��\n");
        }
        if ((int)what_ob->query_amount() < amount)
        {
                return notify_fail("�����" + what_ob->query("name") + "������\n");
        }

   
   me->start_busy(3);
        message_vision(sprintf("$N�ó�%s%s%s�������Ǯׯ��\n",
           chinese_number(amount), what_ob->query("base_unit"),
           what_ob->query("name")), me);
   me->add("balance", what_ob->query("base_value") * amount);
        if ((int)what_ob->query_amount() == amount)
            destruct(what_ob);
        else
            what_ob->add_amount(-amount);

        me->save();

   return 1;
}


int do_check()
{
   int total = (int)this_player()->query("balance");

   if(!total || total < 0)  {
        this_player()->set("balance", 0);
   return notify_fail("���ڱ���ׯû�д�Ǯ��\n");
   }
   write("���ڱ���ׯ������" +
         money_str(total) + "\n");

   return 1;
}

int do_withdraw(string arg)
{
   int amount, v, rv;
   string what;
   object me;

   me = this_player();

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        {
                return notify_fail("�����ʽ��withdraw <����> <���ҵ�λ>\n");
        }
   if( this_player()->is_busy() )
       return notify_fail("��������æ����...��\n");

        if (amount < 1)
        {
                return notify_fail("����ȡ������Ǯ��\n");
        }
        if (file_size("/obj/money/" + what + ".c") < 0)
        {
                return notify_fail("����ȡ��ʲôǮ��\n");
        }
        what = "/obj/money/" + what;
        if ((v = amount * what->query("base_value")) > me->query("balance"))
        {
                return notify_fail("����Ǯ����ȡ��\n");
        }
     if( v < what->query("base_value") )    {
          return notify_fail("Don't try, or I will purge you!\n");
     }

   me->start_busy(1);
   /*
        if( me->query("balance") > me->query("combat_exp")*100)
            rv = v*8/10;
        else
        */
        //cuz there is upper limit now, disabled
        //discount...weiqi,971226.
            rv = v;
        me->add("balance",  -v);
   me->save();
        pay_player(me, rv);

        message_vision(sprintf("$N��������ȡ��%s��\n", money_str(rv)),
                me);
   
   return 1;
}


string money_str(int amount)
{        
   // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "��ͭ��";
        return output;
}


void pay_player(object who, int amount)
{
        int v;
        object ob;

        seteuid(getuid());
        if (amount < 1)
                amount = 1;
        if (v = amount / 10000) {
                ob = new("/obj/money/gold");
                ob->set_amount(amount / 10000);
                ob->move(who);
                amount %= 10000;
        }
        if (amount / 100) {
                ob = new("/obj/money/silver");
                ob->set_amount(amount / 100);
                ob->move(who);
                amount %= 100;
        }
        if (amount) {
                ob = new("/obj/money/coin");
                ob->set_amount(amount);
                ob->move(who);
        }
}

